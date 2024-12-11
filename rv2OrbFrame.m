%
% ------------------------------------------------------------------------------
%
%                           function rv2OrbFrame
%
%  author        : ridanto                15 Februari 2011
%
%  inputs       :
%    r           - ijk position vector            km
%    v           - ijk velocity vector            km / s
% ------------------------------------------------------------------------------

function [out] = rv2OrbFrame (in);

        % -------------------------  implementation   -----------------
        r=[0 0 0];
        v=[0 0 0];
        
        r(1) = in(1);
        r(2)=in(2);
        r(3)=in(3);
        v(1)=in(4);
        v(2)=in(5);
        v(3)=in(6);
        
        magr=mag(r);
        magv=mag(v);
        % -------------------------------------------------------------
        %       determine what type of orbit is involved and set up the
        %       set up angles for the special cases.
        % -------------------------------------------------------------
        
        i_o=v/magv;
        k_o=-r/magr;
        j_o=cross(k_o,i_o);
                       
        out=[i_o;j_o;k_o];

