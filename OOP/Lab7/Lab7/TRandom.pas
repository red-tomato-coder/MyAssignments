unit TRandom;

interface

uses
  System.SysUtils, System.Classes, Vcl.Controls, Vcl.StdCtrls;

type
  TRandomLabel = class(TLabel)
  private
    FMin: Integer;
    FMax: Integer;
    FOnGetMax: TNotifyEvent;
  public
    function GetNumber: Integer;
  published
    property Min: Integer read FMin write FMin default 0;
    property Max: Integer read FMax write FMax default 10;
    property OnGetMax: TNotifyEvent read FOnGetMax write FOnGetMax;
  end;

procedure Register;

implementation

function TRandomLabel.GetNumber: Integer;
var
  i: Integer;
begin
  Randomize;
  i := System.Random(FMax - FMin + 1) + FMin;
  Self.Caption := IntToStr(i);

  if Assigned(FOnGetMax) and (i = FMax) then
    FOnGetMax(Self);

  Result := i;
end;
procedure Register;
begin
  RegisterComponents('Standard', [TRandomLabel]);
end;

end.
