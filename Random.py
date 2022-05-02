from random import random
from string import ascii_letters as ascii
import typing

class Random:
    def __init__(self, value: float = None) -> None:
        if not value:
            self.r = self.randomize()
        else:
            if 0.0 > value < 1.0:
                self.r = value
            else:
                self.r = self.randomize()
    @classmethod
    def randomize(self) -> float:
        self.r = random()
        return self.r
    @classmethod
    def range(self, min: float = 0, max: float = 1) -> float:
        return min + (self.r * (max - min))
    @classmethod
    def chance(self, chance: float = 50) -> bool:
        if chance > self.range(max=100):
            return True
        else:
            return False
    @classmethod
    def irange(self, min: int = 0, max: int = 1) -> int:
        return round(self.range(min, max))
    @classmethod
    def choice(self, array: list) -> typing.Any:
        return array[self.irange(0, len(array)-1)]
    @classmethod
    def choices(self, array: list, length: int) -> typing.Any:
        return [Random(self.randomize()).choice(array) for i in range(length)]
    @classmethod
    def randstr(self, length: int = 0, addchars: str = ""):
        return ''.join(self.choices(ascii, length))
    @classmethod
    def bool_area(self, xsize: int, ysize: int, *, chance: float = 50):
        return [[Random(self.randomize()).chance(chance) for i in range(xsize)] for i in range(ysize)]
    def __float__(self) -> float:
        return self.r
    def __int__(self) -> int:
        return round(self.r)
    def __str__(self) -> str:
        return str(self.r)
