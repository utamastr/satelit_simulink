% IRMUKa, 7 Nopember 2006
% dengan input diameter dan tebal dari spinning wheel
% akan dihitung moment of inertia

function [I] = momentofinertia(u)
     db   = u(1);
      r   = u(2)/2;
    tebal = u(3);
  
    vol_b = pi*r*r*tebal;
    mb = db*vol_b;
    
    Is = mb*r*r/2;
    It = (1/12)*mb*(3*r*r+tebal*tebal);
    
    
    I = [Is, It, It];
end