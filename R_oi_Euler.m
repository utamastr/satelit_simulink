%
% ------------------------------------------------------------------------------
%
%                           function R_oi_Euler
%
%  author        : ridanto                15 Februari 2011
%
% Menentukan matriks rotasi dari TAK Inersial ke Orbital
% untuk berbagai urutan putaran Euler (12)
%
%  inputs       :
%    Omega                rad
%    Inklinasi            rad
%    Argumen of Latitude  rad
%    Type (123, 132, 121, 131, 213, 212, 231, 232, 312, 313, 321, 323)
% ------------------------------------------------------------------------------

function [out] = r_oi_Euler (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        Om    = in(1);
        ink   = in(2);
        argLat= in(3);
        type  = in(4);
        
        co=cos(Om);
        so=sin(Om);
        ci=cos(ink);
        si=sin(ink);
        cu=cos(argLat);
        su=sin(argLat);
        
        if(type==313)
           out=[-ci*cu*so-co*su co*ci*cu-so*su cu*si;
             -so*si co*si -ci;
             ci*so*su-co*cu -cu*so-co*ci*su -si*su];
         
        elseif(type==123)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==121)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==131)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==132)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==231)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==232)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==212)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==213)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==232)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        elseif(type==231)
            out=[0 0 0;
                0 0 0;
                0 0 0];
        end
