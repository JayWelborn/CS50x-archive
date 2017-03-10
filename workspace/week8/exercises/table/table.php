<?php require("header.php"); ?>

    
        <?php 
            print("<table>");
            $num = $_POST["num"];
            
            for($row = 1; $row <= $num; $row++)
            {
                print("<tr> \n");
                
                for($col = 1; $col <= $num; $col++)
                {
                    $x = $col * $row;
                    print("<td>$x</td> \n");
                }
                
                print("</tr> \n");
            }
            print("</table>");
        ?>
        </br>
        <a href = "index.php">Back</a>
    </body>
</html>