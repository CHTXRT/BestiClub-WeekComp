<?php
$uploadDir = 'upload/';
$response = [];

if (!file_exists($uploadDir)) {
    mkdir($uploadDir, 0777, true);
}

foreach ($_FILES['files']['name'] as $key => $name) {
    $tmpName = $_FILES['files']['tmp_name'][$key];
    $filePath = $uploadDir . basename($name);

    if (move_uploaded_file($tmpName, $filePath)) {
        $response[] = $filePath;
    } else {
        $response[] = "Failed to upload $name";
    }
}

header('Content-Type: application/json');
echo json_encode($response);
?>