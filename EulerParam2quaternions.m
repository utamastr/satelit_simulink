%
% ------------------------------------------------------------------------------
%
%                           function EulerParam2quaternions
%
%  author        : ridanto                23 April 2012
%
% ------------------------------------------------------------------------------

function [out] = EulerParam2quaternions (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        fi = in(1)/180*pi; % in radians
        ax = in(2);
        ay = in(3);
        az = in(4);
        
        out=[cos(fi/2); ax*sin(fi/2); ay*sin(fi/2); az*sin(fi/2)];
                
        
       
        
