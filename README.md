# ulisp-tdeck-touch-example
Proof of concept for using the touchscreen on the t-deck with ulisp

# Setup
Follow the [normal setup instructions](http://www.ulisp.com/show?4JAO), then make sure to add the correct touch screen drivers, which reside [here](https://github.com/Xinyuan-LilyGO/T-Deck/tree/master/lib/SensorsLib). That whole folder should go into the Arduino libraries folder and give you access to those drivers, as per the t-deck setup instructions.

# Features
There are two concepts presented here:

## Using the touchscreen as a keyboard modifer

The t-decks keyboard is missing a bunch of keyboard symbols and the default firmware doesnt do much with the alt key. As such we would like a way to get more symbols without reprogramming the keyboard's firmware, which is prohibitively difficult to do (I describe how to do it [here](https://github.com/hasn0life/t-deck-keyboard-ex)). So what I figured we can do is use the touchscreen as a modifer. 

- Hold the screen with either thumb (or other fingers) while typing on the keyboard to access an alternate set of symbols. 
- the alernate symbols are (subject to change by popular demand):
```
    missing mapped	alt symbol
    `       k       ' 
    ~       p       @ 
    %       $       
    ^       a       * 
    &       q       # 
    =       o       + 
    <       t       ( 
    >       y       ) 
    \       u       _ 
    |       g       / 
            
    [       alt-t   (
    ]       alt-y   )
            
    {       n/a
    }       n/a
    tab  	space
```

## Regular touchscreen function to get the touchpoints
extensions.ino contains the `(get-touch-points)` function which returns a list of x and y cons pairs that the touch screen detects (up to 5), or nill if the screen is untouched

# Interaction between the features
If we were to use the touch press to activate another function then it would mess up the keyboard modifier function since the other funcion would get activated. As such we might want an option to disable the other function, or confine the keyboard modifier touch and the other touch function to exclusive areas.