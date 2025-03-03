program Unit1;

uses
  disco, SpherePas;

var
  MySphere, nSphere: TSphere;
  MyDisco: TDisco;
  newRadius: Real;
  i: Integer;

begin
  MySphere := TSphere.Create; //
  MySphere.DisplayStatistics;
  Writeln('===========');

  nSphere := TSphere.Create(15.1); //
  nSphere.DisplayStatistics;
  Writeln('***********');

  newRadius := 5.1;
  MySphere.SetRadius(newRadius);
  Writeln('New Circumference = ', 2.0 * Pi * MySphere.GetRadius:10:5);
  MySphere.DisplayStatistics;

  Writeln('===========');
  MyDisco := TDisco.Create;

  for i := 1 to 5 do
    MyDisco.PatCat;

  Writeln('Котів погладжено: ', MyDisco.GetCatsPatted);

  Writeln(MyDisco.GetVibes);
  MyDisco.Dance;
  Writeln('Пар пропущено: ', MyDisco.OverengineeredSolution);

  Readln; //
end.

