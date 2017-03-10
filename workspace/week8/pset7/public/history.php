<?php

    // configuration
    require("../includes/config.php");
    
    // store id for database query
    $id = $_SESSION["id"];
    
    // get stock symbols from database
    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $id);
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $id);
    $cash = $cash[0]["cash"];
    
    // render form
    render("history.php", ["cash" => $cash, "rows" => $rows, "title" => "History"]);
?>