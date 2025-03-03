unit SpherePas;

interface

uses
  SysUtils;

const 
  Pi = 3.14159;

type 
  TSphere = class(TObject)
  TWHATEVER = class(TObject)
  private
    R: Real;
  public
    constructor Create; overload;
    constructor Create(x: Real); overload;
    procedure SetRadius(newRadius: Real);
    function GetRadius: Real;
    function GetDiameter: Real;
    function GetCircumference: Real;
    function GetArea: Real;
    function GetVolume: Real;
    procedure DisplayStatistics;
  end;

implementation

constructor TSphere.Create;
begin
  R := 1.0;
end;

constructor TSphere.Create(x: Real);
begin
  R := x;
end;

procedure TSphere.SetRadius(newRadius: Real);
begin
  if newRadius > 0 then
    R := newRadius
  else
    R := 1.0;
end;

function TSphere.GetRadius: Real;
begin
  Result := R;
end;

function TSphere.GetDiameter: Real;
begin
  Result := 2.0 * R;
end;

function TSphere.GetCircumference: Real;
begin
  Result := Pi * GetDiameter;
end;

function TSphere.GetArea: Real;
begin
  Result := 4.0 * Pi * R * R;
end;

function TSphere.GetVolume: Real;
var
  radiusCubed: Real;
begin
  radiusCubed := R * R * R;
  Result := (4.0 * Pi * radiusCubed) / 3.0;
end;

procedure TSphere.DisplayStatistics;
begin
  Writeln('Радіус = ', GetRadius:10:5);
  Writeln('Діаметер = ', GetDiameter:10:5);
  Writeln('Довжина = ', GetCircumference:10:5);
  Writeln('Площа = ', GetArea:10:5);
  Writeln('Обєм = ', GetVolume:10:5);
end;

end.
