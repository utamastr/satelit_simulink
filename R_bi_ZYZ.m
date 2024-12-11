%
% ------------------------------------------------------------------------------
%
%                           function R_bi_ZYZ
%
%  author        : ridanto                19 April 2012
%
% ------------------------------------------------------------------------------

function [out] = R_bi_ZYZ (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        teta1 = in(1);
        teta2 = in(2);
        teta3 = in(3);
                
        c1=cos(teta1);
        s1=sin(teta1);
        c2=cos(teta2);
        s2=sin(teta2);
        c3=cos(teta3);
        s3=sin(teta3);
        
                               % harus dicek dg tulisan tangan saya
        out=[c3*c2*c1-s3*s1 c3*c2*s1+s3*c1 -c3*s2;
             -s3*c2*c1-c3*s1 -s3*c2*s1+c3*c1 s3*s2;
             s2*c1 s2*s1 c2];
        
