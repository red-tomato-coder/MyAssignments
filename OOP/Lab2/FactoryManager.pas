unit FactoryManager;

interface

uses
  SysUtils;

const
  DEFAULT_PRODUCTION = 0;

type
  TFactoryManager = class(TObject)
  private
    ProducedItems: Integer;
    TotalDefects: Integer;
  public
    constructor Create;
    function GetProducedCount: Integer;
    function GetDefectRate: Real;
    procedure ProduceItem(defective: Boolean);
    procedure ResetProduction;
  end;

implementation

constructor TFactoryManager.Create;
begin
  ProducedItems := 0;
  TotalDefects := 0;
end;

function TFactoryManager.GetProducedCount: Integer;
begin
  Result := ProducedItems;
end;

function TFactoryManager.GetDefectRate: Real;
begin
  if ProducedItems = 0 then
    Result := DEFAULT_PRODUCTION
  else
    Result := (TotalDefects / ProducedItems) * 100;
end;

procedure TFactoryManager.ProduceItem(defective: Boolean);
begin
  Inc(ProducedItems);
  if defective then
    Inc(TotalDefects);
end;

procedure TFactoryManager.ResetProduction;
begin
  ProducedItems := 0;
  TotalDefects := 0;
end;

end.

