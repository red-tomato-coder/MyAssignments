unit BallU;


interface

uses SphereU, SysUtils;

type
  Ball = class(Sphere)
  private
    Density: Real;
  public
    constructor Create(x, y, z, r, d: Real);
    function GetWeight: Real;
    function GetDetails: String;
  end;

implementation

constructor Ball.Create(x, y, z, r, d: Real);
begin
  inherited Create(x, y, z, r);
  Density := d;
end;

function Ball.GetWeight: Real;
begin
  Result := Volume * Density;
end;

function Ball.GetDetails: String;
begin
  Result := 'Coords Center = ' + GetPoint + sLineBreak +
            'Volume Sphere = ' + FloatToStrF(Volume, ffFixed, 10, 4) + sLineBreak +
            'Density = ' + FloatToStrF(Density, ffFixed, 10, 4) + sLineBreak +
            'Weight = ' + FloatToStrF(GetWeight, ffFixed, 10, 4);
end;

end.

