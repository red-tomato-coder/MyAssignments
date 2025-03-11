program Unit1;

uses
  SpherePas, BallU;

var
  MySphere, nSphere: TSphere;
  MyBall: Ball;
  newRadius: Real;

begin
  MySphere := TSphere.Create;
  MySphere.DisplayStatistics;
  Writeln('===========');

  nSphere := TSphere.Create(15.1);
  nSphere.DisplayStatistics;
  Writeln('***********');

  newRadius := 5.1;
  MySphere.SetRadius(newRadius);
  Writeln('Нова довжина = ', 2.0 * Pi * MySphere.GetRadius:10:5);
  MySphere.DisplayStatistics;

  Writeln('===========');

  MyBall := Ball.Create(5, 7.8, 'Моя куля', RED);
  Writeln('Інформація про кулю: ', MyBall.GetBallInfo);

  Readln;
end.
