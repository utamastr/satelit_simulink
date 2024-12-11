%
% ------------------------------------------------------------------------------
%
%                           function find_ArgLat
%
%  author        : ridanto                15 Februari 2011
%
%  inputs       :
%    Omega                rad
%    r                    km
% ------------------------------------------------------------------------------

function [out] = find_ArgLat (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        rad2deg=180/pi;
                
        Om    = in(1);
        r(1)   = in(2);
        r(2)   = in(3);
        r(3)   = in(4);
        
        co=cos(Om);
        so=sin(Om);
        
        ir=r/mag(r);
        in=[co;so;0];
                                
        out=acos(dot(ir,in))*rad2deg;
