<?php
class Random
{
    public function __constructor()
    {
        //
    }
    public function random()
    {
        return mt_rand() / mt_getrandmax();
    }
    public function range(float $min = 0, float $max = 1)
    {
        return $min + ($this->random() * ($max - $min));
    }
    public function irange(int $min = 0, int $max = 1)
    {
        return (int)($this->range($min, $max));
    }
    public function choice($array)
    {
        return $array[$this->irange(0, count($array))];
    }
    public function choices($array, int $length)
    {
        $rarray = [];
        for ($i=0; $i < $length; $i++)
        {
            $rarray[$i] = $this->choice($array);
        }
        return $rarray;
    }
    public function strrange(int $length, string $addchars = "")
    {
        $rstr = "";
        $rastr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".$addchars;
        $_ = strlen($rastr);
        for ($i=0; $i < $length; $i++)
        {
            $rstr .= $rastr[$this->irange(0, $_)];
        }
        return $rstr;
    }
    public function chance(float $chance = 50.0)
    {
        if ($this->range(0, 100) <= $chance)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
?>
