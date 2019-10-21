module Chs67 where

--don't delete the import, obviously
--remember to include function types (3 points each)


sumdown :: Int -> Int
sumdown n | n > 0 = n + sumdown (n-1)
          | n == 0 = 0


euclid :: Int -> Int -> Int
euclid x y | x == y     = x
           | x > y      = euclid (x-y) y
           | otherwise  = euclid x (y-x)


sum' :: [Int] -> Int
sum' [] = 0
sum' (x:xs) = x + sum' xs

take':: Int -> [a] -> [a]
take' _ []               = []
take' x (y:ys)  | x == 0 = []
                | x == 1 = y : []
                | otherwise = y : take' (x-1) ys

last' :: [a] -> a
last' (x:xs)    | null xs = x
                | otherwise = last' xs

dec2int' :: [Int] -> Int
dec2int' = foldl(\x y -> 10*x + y)0

altmap :: (a->b) -> (a->b) -> [a] -> [b]
altmap _ _ []           = []
altmap a _ (x:[])       = a x : []
altmap a b (x:y:[])     = a x : b y : []
altmap a b (x:y:zs)     = a x : b y : altmap a b zs


--define your own function(s) to help with luhn

luhn _ = False