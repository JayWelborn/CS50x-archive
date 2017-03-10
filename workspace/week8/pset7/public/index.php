<?php

    // configuration
    require("../includes/config.php"); 
    
    if($_SESSION["id"] !== "")
    {
        // store id for database query
        $id = $_SESSION["id"];
        
        // get stock symbols from database
        $rows = CS50::query("SELECT * FROM portfolio WHERE user_id = ?", $id);
        
        // get user's cash balance from database
        $user_cash = CS50::query("SELECT cash FROM users WHERE id = ?", $id);
        $cash = $user_cash[0]["cash"];
        $cash = number_format($cash, 2);
        
        // lookup info for each of the user's stocks
        $positions = [];
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $positions[] = [
                "name" => $stock["name"],
                "price" => round($stock["price"], 2),
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
                ];
            }
        }
        
        // render portfolio
        render("portfolio.php", ["cash" => $cash, "positions" => $positions, "title" => "Portfolio"]);
    }

    

?>
