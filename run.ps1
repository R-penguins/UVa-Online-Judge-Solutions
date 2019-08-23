<#
Runs and times the source code with specified input in $inputFile
Use program name as command line argument
#>
param (
    [Parameter(Mandatory = $true)]
    [string]
    $id
)
$srcFolder = "./bin/"
$inputFile = "in.txt"
$outputFile = "out.txt"
$time = (Measure-Command {Get-Content $inputFile | & $srcFolder$id > $outputFile}).TotalSeconds
Write-Output "Run time: $time seconds"