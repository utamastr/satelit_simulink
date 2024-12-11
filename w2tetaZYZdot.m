%
% ------------------------------------------------------------------------------
%
%                           function w2tetaZYZdot
%
%  author        : ridanto                23 April 2012
%
% ------------------------------------------------------------------------------

function [tetadot] = w2qdot (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        teta1=in(1);
        teta2=in(2);
        teta3=in(3);
        w1=in(4);
        w2=in(5);
        w3=in(6);
        
        s1=sin(teta1);
        s2=sin(teta2);
        s3=sin(teta3);
        c1=cos(teta1);
        c2=cos(teta2);
        c3=cos(teta3);
        
        A=[-c3*s2 s3 0;
            s3*s2 c3 0;
            c2 0 1];
            
        B=inv(A);
        
        w=[w1;w2;w3];
        
        tetadot=B*w;
                
        
       
        
