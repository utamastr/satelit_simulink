% ----------------------------------------------------------------------------
%
%                           function modulo
%
%  this function finds the modulous value. The result is positive or negative.
%
%  author        : david vallado                  719-573-2600    4 jun 2002
%
%  revisions
%                -
%
%  inputs          description                    range / units
%    x           - input argument
%    xv          - input argument to mod with
%
%  outputs       :
%    y           - answer
%
%  locals        :
%    none        -
%
%  coupling      :
%    none        -
%
%  references    :
%    vallado       2001, xx
%
% y = modulo (x,xv);
% ----------------------------------------------------------------------------

function y = modulo (x,xv);
%#eml
        y = x - xv * fix(x / xv);

