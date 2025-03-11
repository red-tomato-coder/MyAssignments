unit BallU;

interface

uses
  SysUtils, SpherePas;

type
  Colored = (RED, GREEN, BLUE, CYAN, YELLOW, WHITE, BLACK);

  Ball = class(TSphere)
  private
    theName: String;
    c: Colored;
    SpecificWeight: Real;
    x, y, z: Real;  // Add coordinate storage
    radius: Real;    // Add radius storage
  public
    constructor Create(ax, ay, az, ar, aweight: Real; const initName: String; initColor: Colored);
    procedure SetName(newName: String);
    procedure SetColor(newColor: Colored);
    function GetName: String;
    function GetColor: Colored;
    function GetPoint: String;
    function GetColorName: String;
    function GetWeight: Real;
    function GetBallInfo: String;
    procedure ResetBall(newRadius: Real; newName: String; newColor: Colored);
    function GetX: Real;  // Add coordinate getters
    function GetY: Real;
    function GetZ: Real;
    function GetRadius: Real;
    property Volume: Real read GetVolume;  // Add volume calculation
  end;

implementation

constructor Ball.Create(ax, ay, az, ar, aweight: Real; const initName: String; initColor: Colored);
begin
  inherited Create;  // Call parameterless base constructor
  x := ax;
  y := ay;
  z := az;
  radius := ar;
  SpecificWeight := aweight;
  theName := initName;
  c := initColor;
end;

function Ball.GetX: Real;
begin
  Result := x;
end;

function Ball.GetY: Real;
begin
  Result := y;
end;

function Ball.GetZ: Real;
begin
  Result := z;
end;

function Ball.GetRadius: Real;
begin
  Result := radius;
end;

function Ball.GetVolume: Real;
begin
  Result := (4/3) * Pi * radius * radius * radius;
end;

function Ball.GetPoint: String;
begin
  Result := 'Point: (' + FloatToStr(x) + ', ' + FloatToStr(y) + ', ' + FloatToStr(z) + ')';
end;

// Rest of the methods remain the same as previous version from here...

procedure Ball.SetName(newName: String);
begin
  theName := newName;
end;

procedure Ball.SetColor(newColor: Colored);
begin
  c := newColor;
end;

function Ball.GetName: String;
begin
  Result := theName;
end;

function Ball.GetColor: Colored;
begin
  Result := c;
end;

function Ball.GetColorName: String;
begin
  case c of
    RED: Result := 'RED';
    GREEN: Result := 'GREEN';
    BLUE: Result := 'BLUE';
    CYAN: Result := 'CYAN';
    YELLOW: Result := 'YELLOW';
    WHITE: Result := 'WHITE';
    BLACK: Result := 'BLACK';
  end;
end;

function Ball.GetWeight: Real;
begin
  Result := Volume * SpecificWeight;
end;

function Ball.GetBallInfo: String;
begin
  Result := 'Корди: ' + GetPoint() + ', Радіус: ' + FloatToStr(radius) +
            ', Об''єм: ' + FloatToStr(Volume) + ', Маса: ' + FloatToStr(GetWeight) +
            ', Колір: ' + GetColorName + ', Ім''я: ' + GetName;
end;

procedure Ball.ResetBall(newRadius: Real; newName: String; newColor: Colored);
begin
  radius := newRadius;
  SetName(newName);
  SetColor(newColor);
end;

end.
