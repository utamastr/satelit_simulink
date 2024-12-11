%
% ------------------------------------------------------------------------------
%
%                           function R_oi_Euler
%
%  author        : ridanto                15 Februari 2011
%
% ------------------------------------------------------------------------------

function [out] = r_oi_Euler321 (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        fi   = in(1);
        teta = in(2);
        psi  = in(3);
                
        c1=cos(fi);
        s1=sin(fi);
        c2=cos(teta);
        s2=sin(teta);
        c3=cos(psi);
        s3=sin(psi);
        
                               
        out=[c2*c1 c2*s1 -s2;
             -c3*s1+s3*s2*c1 c3*c1+s3*s2*s1 s3*c2;
             s3*s1+c3*s2*c1 -s3*c1+c3*s2*s1 c3*c2];
        
