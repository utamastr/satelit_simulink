%
% ------------------------------------------------------------------------------
%
%                           function R_bi_ZYZ
%
%  author        : ridanto                19 April 2012
%
% ------------------------------------------------------------------------------

function [out] = DCM2EulerParam (R);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        fi = acos((trace(R)-1)/2); % in radians
        ax = 1/(2*sin(fi))*(R(3,2)-R(2,3));
        ay = 1/(2*sin(fi))*(R(1,3)-R(3,1));
        az = 1/(2*sin(fi))*(R(2,1)-R(1,2));
        
        out=[fi*180/pi; ax; ay; az];
                
        
       
        
