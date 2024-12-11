function [R] = S1_321(teta)

 t1 = teta(1);
 t2 = teta(2);
 t3 = teta(3);

 R(1,1)=0;
 R(1,2)=sin(t3)/cos(t2);
 R(1,3)=cos(t3)/cos(t2);
 R(2,1)=0;
 R(2,2)=cos(t3);
 R(2,3)=-sin(t3);
 R(3,1)=1;
 R(3,2)=sin(t3)*sin(t2)/cos(t2);
 R(3,3)=cos(t3)*sin(t2)/cos(t2);
 

end