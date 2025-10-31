% function [delta_Uopt_OSQP] = OSQP_MPC_helper(N,num_ctrl,H,f,A_ineq,lb,ub)
% persistent OSQP_instance
% 
% if isempty(OSQP_instance)
%     OSQP_instance = osqp;
% 
%     % This checks if there are any rows in lower bound vector that are larger than corresponding row in upper bound vector
%     bad = find(lb > ub);
%     if ~isempty(bad)
%         error('Row %d has l > u: l=%g, u=%g', bad(1), lb(bad(1)), ub(bad(1)));
%     end
% 
%     % Setting up the OSQP, only happens once the first time function is called
%     OSQP_instance.setup(H,f,A_ineq,lb,ub,'warm_start',true,'verbose',false);
% else
%     bad = find(lb > ub);
%     if ~isempty(bad)
%         error('Row %d has l > u: l=%g, u=%g', bad(1), lb(bad(1)), ub(bad(1)));
%     end
% 
%     % Updating the OSQP
%     OSQP_instance.update('q',f,'l',lb,'u',ub,'Px',H,'Ax',A_ineq); % Update OSQP problem step; need to update all fields since Adaptive MPC
%     opt_OSQP_vec = OSQP_instance.solve(); % Solving optimization problem step
%     delta_Uopt_OSQP =  double(opt_OSQP_vec.x(1:N*num_ctrl,:)); % extracting predicted optimized control signal without the slack variables
% end
% 
% end

function [delta_Uopt_OSQP] = OSQP_MPC_helper(N, num_ctrl, H, f, A_ineq, lb, ub)
% z = [Δu; s_vh; s_ah+; s_ah-], we return first N*num_ctrl entries (Δu)
persistent OSQP_instance maskP maskA nvar ncon setup_done

% ------- basic checks -------
if any(~isfinite(lb)) || any(~isfinite(ub))
    error('lb/ub contain non-finite values.');
end
bad = find(lb > ub, 1);
if ~isempty(bad)
    error('Bounds row %d has l>u: l=%g, u=%g', bad, lb(bad), ub(bad));
end

% Ensure sparse
H = sparse(H);
A_ineq = sparse(A_ineq);

if isempty(setup_done)
    % Store sizes
    nvar = size(H,1);
    ncon = size(A_ineq,1);

    % P pattern: upper triangle of H (structure only)
    Ppat = sparse(triu(H ~= 0));
    % A pattern: structure only
    Apat = sparse(A_ineq ~= 0);

    % Save logical masks to pull numeric values in the SAME order later
    maskP = Ppat ~= 0;
    maskA = Apat ~= 0;

    % Numeric placeholders for setup (same structure)
    P0 = sparse(triu(H));                  % numeric P with same pattern
    A0 = A_ineq;                           % numeric A (pattern fixed)

    OSQP_instance = osqp;
    OSQP_instance.setup(P0, f, A0, lb, ub, ...
        'warm_start', true, 'verbose', false);

    setup_done = true;

    % ---- First solve (so caller gets an answer on first call too) ----
    res = OSQP_instance.solve();
    z = res.x;
else
    % Update numerics only (structure must be unchanged)
    % Pull nonzeros in the same order as setup patterns
    Px = full(H(maskP));        % vector of P upper-tri nonzeros
    Ax = full(A_ineq(maskA));   % vector of A nonzeros

    OSQP_instance.update('q', f, 'l', lb, 'u', ub, 'Px', Px, 'Ax', Ax);
    
    res = OSQP_instance.solve();
    z = res.x;
end

% Return Δu block
delta_Uopt_OSQP = double(z(1:N*num_ctrl, :));
end
