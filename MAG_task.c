#import <Foundation/Foundation.h>

NSString *capString(NSString inputStr[]) {

  NSMutableString tempStr;


  static int qcnt = 0;
  static char prev_char = "";
  static char next_char = "";
  static char cur_char = "";
  static char rch  = "";


  tempStr = [[[inputStr subStringToIndex:1] uppercaseString] stringByAppendingString:[inputStr subStringFromIndex:1]];

  //if first char is space
  if ([tempStr hasPrefix:@" "] && [tempStr length] > 1) {
    tempStr = [tempStr substringFromIndex:1];
  }

  //if last char is space
  if ([tempStr hasSuffix:@" "] && [tempStr length] > 1) {
    tempStr = [tempStr substringWithRange:NSMakeRange(0, [tempStr length]-2)];
  }

  //if previous char before last is also space
  if ([tempStr characterAtIndex:[tempStr length]-2]==" ") {
    [tempStr deleteCharactersInRange:NSMakeRange([tempStr length]-2,1)];	  
  }


  for(int i =0 ;i<[tempStr length]-1; i++) {

    if (i>0) {
      prev_char = [tempStr characterAtIndex:i-1];
    }
  
    cur_char = [tempStr characterAtIndex:i];
  
    next_char = [tempStr characterAtIndex:i+1];

    if (cur_char=="i") && (prev_char==" ") && ((next_char=="'")||(next_char==" ")) {
      [tempStr stringByReplacingCharactersInRange:NSMakeRange(i,1) withString:@"I"];
    } else { 
    
	  if (prev_char==" ") && (cur_char>=65) && (cur_char<91) {
        rch = cur_char+32;
        [tempStr stringByReplacingCharactersInRange:NSMakeRange(i,1) withString:rch];
      }
    }
  
    if (cur_char=="\"") {
      qcnt++;
   
      if ((qcnt % 2) == 1) {
	    if (prev_char!=" ") {
	 	  [tempStr insertString:@" " atIndex:i];
	    } else if (next_char==" ")  {
	      [tempStr deleteCharactersInRange:NSMakeRange(i+1,1)];	
	    }
	  } else {
	    if (prev_char==" ") {
	      [tempStr deleteCharactersInRange:NSMakeRange(i-1,1)];	
	    }	 
	  }
    }

    if (cur_char=="'") {
      if (prev_char==" ") {
	    [tempStr deleteCharactersInRange:NSMakeRange(i-1,1)];	
	   
	  } else if (next_char==" ")  {
	    [tempStr deleteCharactersInRange:NSMakeRange(i+1,1)];	
	  }
	  if (next_char>=65) && (next_char<91) {
	    rch = cur_char+32;
        [tempStr stringByReplacingCharactersInRange:NSMakeRange(i,1) withString:rch];
      }	  
    }

    if (cur_char==" ") && (next_char==",") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i,1)];	
    }

    if (cur_char==" ") && (next_char==".") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i,1)];	
    }

    if (cur_char==" ") && (next_char=="!") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i,1)];	
    }

    if (cur_char==" ") && (next_char=="?") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i,1)];	
    }

    if (cur_char==" ") && (next_char==":") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i,1)];	
    }

    if (cur_char==" ") && (next_char==";") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i,1)];	
    }

    if (cur_char==" ") && (next_char=="...") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i,1)];	
    }

    if (cur_char==" ") && (next_char==")") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i,1)];	
    }
  
    if (cur_char=="(") && (next_char==" ") {
	  [tempStr deleteCharactersInRange:NSMakeRange(i+1,1)];	
    }
  
  //adding spaces if absent after special signs
  
    if (cur_char==",") && (next_char!=" ") {
	  [tempStr insertString:@" " atIndex:i+1];
    }

    if (cur_char==".") && (next_char!=" ") {
	
	  if (next_char>97) && (next_char<123) {
	    rch = cur_char-32;
        [tempStr stringByReplacingCharactersInRange:NSMakeRange(i,1) withString:rch];
      }
	
	  [tempStr insertString:@" " atIndex:i+1];	
    }

    if (cur_char=="!") && (next_char!=" ") {
	
	  if (next_char>97) && (next_char<123) {
	    rch = cur_char-32;
        [tempStr stringByReplacingCharactersInRange:NSMakeRange(i,1) withString:rch];
      }
	
  	  [tempStr insertString:@" " atIndex:i+1];
    }

    if (cur_char=="?") && (next_char!=" ") {
	
	  if (next_char>97) && (next_char<123) {
	    rch = cur_char-32;
        [tempStr stringByReplacingCharactersInRange:NSMakeRange(i,1) withString:rch];
      }
	
	  [tempStr insertString:@" " atIndex:i+1];	
    }

    if (cur_char==":") && (next_char!=" ") {
	  [tempStr insertString:@" " atIndex:i+1];
    }
  
    if (cur_char==";") && (next_char!=" ") {
	  [tempStr insertString:@" " atIndex:i+1];
    }

    if (cur_char=="...") && (next_char!=" ") {
    
	  if (next_char>97) && (next_char<123) {
	    rch = cur_char-32;
        [tempStr stringByReplacingCharactersInRange:NSMakeRange(i,1) withString:rch];
      }
	
  	  [tempStr insertString:@" " atIndex:i+1];	
    }

    if (cur_char==")") && (next_char!=" ") {
	  [tempStr insertString:@" " atIndex:i+1];
    }
    
    if (cur_char=="(") && (prev_char!=" ") {
	  [tempStr insertString:@" " atIndex:i+1];
    }
  
    if (cur_char=="-") {
      if (prev_char!=" ") {
	    [tempStr insertString:@" " atIndex:i];
	   
  	  } else if (next_char!=" ")  {
	    [tempStr insertString:@" " atIndex:i+1];
	  }
    }
  }


  return tempStr;
}
