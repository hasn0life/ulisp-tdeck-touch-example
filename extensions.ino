/*
 User Extensions
*/
  
// Definitions

object *fn_get_touch_points (object *args, object *env) {
  #if defined(touchscreen)
  int16_t x[5], y[5];
  uint8_t touched = 0;
  object *result = nil;
  do {
    touched = touch.getPoint(x, y, touch.getSupportTouchPoint());
    if (touched > 0) {
      //start from the end of the list so we dont have to reverse it
      for (int i = touched; i > 0; --i) {
        result = cons(cons(number(x[i-1]), number(y[i-1])), result);
      }
    }
  } while(touch.isPressed());
  return result;

  #else
  return nil;
  #endif
}

// Symbol names
const char string_gettouchpoints[] PROGMEM = "get-touch-points";


// Documentation strings
const char doc_gettouchpoints[] PROGMEM = "(get-touch-points)\n"
"Returns all the points being touched on the screen in a list of x,y pairs or an empty list";


// Symbol lookup table
const tbl_entry_t lookup_table2[] PROGMEM = {
  { string_gettouchpoints, fn_get_touch_points, 0200, doc_gettouchpoints }
};

// Table cross-reference functions

tbl_entry_t *tables[] = {lookup_table, lookup_table2};
const unsigned int tablesizes[] = { arraysize(lookup_table), arraysize(lookup_table2) };

const tbl_entry_t *table (int n) {
  return tables[n];
}

unsigned int tablesize (int n) {
  return tablesizes[n];
}