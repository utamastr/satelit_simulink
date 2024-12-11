% ------------ Buka Simulink Model ---------
% ------------------------------------------
open_system('General_batang');

tfinal=3600;

% ----------Jalankan model simulink -----------------
% -----------------------------------------------------
set_param('General_batang', 'SimulationCommand', 'start')
waktu = 0.0;
  rad2deg = 180/3.14159;
 j=1;
while(waktu<(tfinal-100))
 
pause(0.1)
 
waktuGui=get_param('General_batang/detik','RuntimeObject');
waktu = get(waktuGui.InputPort(1),'Data');
harga_waktu = sprintf('waktu = %.1f s',waktu)

tetaGui=get_param('General_batang/gui3','RuntimeObject');
teta = get(tetaGui.InputPort(1),'Data');

harga_teta1 = sprintf('teta1 = %.2f deg', teta(1))

harga_teta2 = sprintf('teta2 = %.2f deg', teta(2))


harga_teta3 = sprintf('teta3 = %.2f deg', teta(3))


 j=j+1;
end
% -------------- Stop Simulasi Simulink bila waktu > simTime ----
% ---------------------------------------------------------------
set_param('General_batang', 'SimulationCommand', 'stop')
close_system('General_batang');