{"filter":false,"title":"counter.php","tooltip":"/week8/exercises/generic/counter.php","undoManager":{"mark":0,"position":0,"stack":[[{"start":{"row":0,"column":0},"end":{"row":13,"column":2},"action":"insert","lines":["<?php","","    session_start();","    if(isset($_SESSION[\"counter\"]))","    {","        $counter = $_SESSION[\"counter\"];","    }","    else","    {","        $counter = 0;","    }","    ","    $_SESSION[\"counter\"] = $counter + 1","?>"],"id":1}],[{"start":{"row":10,"column":0},"end":{"row":11,"column":0},"action":"remove","lines":["    }",""],"id":3}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":13,"column":2},"end":{"row":13,"column":2},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1478120055873,"hash":"af46a9ab6733464497db8154753adf65562da272"}