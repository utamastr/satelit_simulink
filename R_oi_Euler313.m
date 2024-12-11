%
% ------------------------------------------------------------------------------
%
%                           function R_oi_Euler
%
%  author        : ridanto                15 Februari 2011
%
%  inputs       :
%    Omega                rad
%    Inklinasi            rad
%    Argumen of Latitude  rad
% ------------------------------------------------------------------------------

function [out] = r_oi_Euler313 (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        Om    = in(1);
        ink   = in(2);
        argLat= in(3);
                
        %co=cos(Om);
        %so=sin(Om);
        %ci=cos(ink);
        %si=sin(ink);
        %cu=cos(argLat);
        %su=sin(argLat);
        
        c1=cos(Om);
        s1=sin(Om);
        c2=cos(ink);
        s2=sin(ink);
        c3=cos(argLat);
        s3=sin(argLat);
        
                               
        %out=[-ci*cu*so-co*su co*ci*cu-so*su cu*si;
            % -so*si co*si -ci;
             %ci*so*su-co*cu -cu*so-co*ci*su -si*su];
         
         out=[c3*c1-s3*c2*s1 c3*s1+s3*c2*c1 s3*s2;
              -s3*c1-c3*c2*s1 -s3*s1+c3*c2*c1 c3*s2;
              s2*s1 -s2*c1 c2];
        
