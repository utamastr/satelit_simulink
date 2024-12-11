%
% ------------------------------------------------------------------------------
%
%                           function rv2OrbFrame_Euler313
%
%  author        : ridanto                15 Februari 2011
%
%  inputs       :
%    Omega                rad
%    Inklinasi            rad
%    Argumen of Latitude  rad
% ------------------------------------------------------------------------------

function [out] = rv2OrbFrame_Euler313 (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        Om    = in(1);
        ink   = in(2);
        argLat= in(3);
        
        co=cos(Om);
        so=sin(Om);
        ci=cos(ink);
        si=sin(ink);
        cu=cos(argLat);
        su=sin(argLat);
        
        
                        
        out=[ci*cu*so+co*su co*ci*cu-so*su -cu*si;
             -so*si -co*si -ci;
             ci*so*su-co*cu cu*so-co*ci*su -si*su];
