<# Downloads problem statements from the UVa Online Judge
 # Write problem numbers as command line arguments, seperated by commas  
 # Output directory can be changed in $outputFolder
 #>
param ([string[]]$problemNumbers)
$outputFolder = "./pdf/"
foreach ($number in $problemNumbers) {
    Write-Output "Downloading $number.pdf ..."
    $problemFolder = $number.Substring(0, $number.Length - 2)
    Invoke-WebRequest "https://uva.onlinejudge.org/external/$problemFolder/$number.pdf" -OutFile "$outputFolder$number.pdf"
}