program Unit2;

uses
  SysUtils, LeCar, MeowCar;

var
  MyCar: TCar;
  MyMeowCar: TMeowCar;

begin

  MyCar := TCar.Create('Тойота', 'Королла', 15.0);
  MyCar.Refuel(30.0);
  MyCar.Accelerate(60.0);
  MyCar.Brake(1.0);
  MyCar.Drive(100.0);
  MyCar.DisplayStats;
  writeln('====================');

  MyMeowCar := TMeowCar.Create('Нявкар', 'Нянкет', 312.0);
  MyMeowCar.Refuel(9999.0);
  MyMeowCar.Accelerate(101.0);
  MyCar.Brake(15.0);
  MyMeowCar.Drive(1.0);
  MyMeowCar.Nyan();
  MyMeowCar.DisplayStats;

  Readln();

end.
