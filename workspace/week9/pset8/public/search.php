<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
    
    while(empty($places))
    {
        // check for postal code match
        $places = CS50::query("SELECT * FROM places WHERE postal_code LIKE ?", $_GET["geo"] . "%");
        if (!empty($places))
        {
            break;
        }
        
        // check city/state
        $places = CS50::query("SELECT * FROM places WHERE MATCH(place_name, admin_code1) 
                                                        AGAINST (?)", $_GET["geo"]);
        if (!empty($places))
        {
            break;
        }
        
        // check city/state
        $places = CS50::query("SELECT * FROM places WHERE MATCH(place_name, admin_name1) 
                                                        AGAINST (?)", $_GET["geo"]);
        if (!empty($places))
        {
            break;
        }
        
        // check state name
        $places = CS50::query("SELECT * FROM places WHERE admin_code1 = ?", $_GET["geo"]);
        if (!empty($places))
        {
            break;
        }
        
        // check for all cities with that name or similar names
        $places = CS50::query("SELECT* FROM places WHERE place_name LIKE ?", "%" . $_GET["geo"] . "%");
        if (!empty($places))
        {
            break;
        }
    
        print("Query Error");
        break;
    }

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>