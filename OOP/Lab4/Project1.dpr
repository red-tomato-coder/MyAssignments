program Project1;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils,
  SphereU in 'SphereU.pas',
  BallU in 'BallU.pas',
  PointU in 'PointU.pas',
  SichU in 'SichU.pas';

var
  x, y, z, r, d: Real;
  B: Ball;
begin
  Write('Enter x, y, z coordinates: ');
  ReadLn(x, y, z);
  Write('Enter radius: ');
  ReadLn(r);
  Write('Enter density: ');
  ReadLn(d);

  B := Ball.Create(x, y, z, r, d);
  WriteLn('Ball info: ', B.GetDetails);

  ReadLn;
end.
