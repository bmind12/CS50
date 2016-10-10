<?php

    // configuration
    require("../includes/config.php"); 

    // render history
    $records = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    render("history_form.php", ["title" => "History", "records" => $records]);
    
?>