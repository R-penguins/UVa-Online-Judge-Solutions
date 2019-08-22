param ([string[]]$problemNumbers)
foreach ($number in $problemNumbers) {
    Write-Output "Downloading $number.pdf ..."
    $problemFolder = $number.Substring(0, $number.Length - 2)
    Invoke-WebRequest "https://uva.onlinejudge.org/external/$problemFolder/$number.pdf" -OutFile "./pdf/$number.pdf"
}