<# Downloads problem statements from the UVa Online Judge
 # Write problem numbers as command line arguments, seperated by commas  
 # Output directory can be changed in $outputFolder
 # Use parameter "-View" to open the document after download
 #>
param ([string[]]$problemIDs, [switch]$View)
$outputFolder = "./pdf/"
foreach ($id in $problemIDs) {
    Write-Output "Downloading $id.pdf ..."
    $problemFolder = $id.Substring(0, $id.Length - 2)
    Invoke-WebRequest "https://uva.onlinejudge.org/external/$problemFolder/$id.pdf" -OutFile "$outputFolder$id.pdf"
    if ($View) {
        Start-Process "$outputFolder$id.pdf"
    }
}