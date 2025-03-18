unit LeCar;

interface

uses
  SysUtils, Math;

type
  TCar = class(TObject)
  private
    FMake: String;
    FModel: String;
    FSpeed: Real; // км / год
    FFuelEfficiency: Real; // км/милі
    FFuelLevel: Real; // літри
  public
    constructor Create(make, model: String; fuelEfficiency: Real);
    procedure Accelerate(amount: Real); virtual;
    procedure Brake(amount: Real);
    procedure Drive(distance: Real);
    procedure Refuel(amount: Real);
    procedure DisplayStats;
  end;

implementation

constructor TCar.Create(make, model: String; fuelEfficiency: Real);
begin
  FMake := make;
  FModel := model;
  FFuelEfficiency := fuelEfficiency;
  FSpeed := 0.0;
  FFuelLevel := 0.0;
end;

procedure TCar.Accelerate(amount: Real);
begin
  if amount > 0 then
    FSpeed := FSpeed + amount;
end;

procedure TCar.Brake(amount: Real);
begin
  if amount > 0 then
    FSpeed := Max(0, FSpeed - amount); // Шоби не було менше 0
end;

procedure TCar.Drive(distance: Real);
var
  fuelUsed: Real;
begin
  fuelUsed := distance / FFuelEfficiency;
  if fuelUsed <= FFuelLevel then
  begin
    FFuelLevel := FFuelLevel - fuelUsed;
    Writeln('Проїхало ', distance:0:2, ' км. Використано: ', fuelUsed:0:2, ' літрів палива.');
  end
  else
    Writeln('Недостатньо, аби проїхати ', distance:0:2, ' км.');
end;

procedure TCar.Refuel(amount: Real);
begin
  if amount > 0 then
    FFuelLevel := FFuelLevel + amount;
end;

procedure TCar.DisplayStats;
begin
  Writeln('Виробник: ', FMake);
  Writeln('Модель: ', FModel);
  Writeln('Швидкість: ', FSpeed:0:2, ' км/г');
  Writeln('Ефективність палива: ', FFuelEfficiency:0:2, ' км/л');
  Writeln('Рівень палива: ', FFuelLevel:0:2, ' літрів');
  Writeln('Дальність: ', (FFuelLevel * FFuelEfficiency):0:2, ' км');
end;

end.
