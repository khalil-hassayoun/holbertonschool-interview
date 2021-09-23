UTF-8 is a variable-width character encoding used for electronic communication. Defined by the Unicode Standard, the name is derived from Unicode (or Universal Coded Character Set) Transformation Format – 8-bit
## Layout of UTF-8 byte sequences
 - 1 Byte	0xxxxxxx	
 - 2 Bytes	110xxxxx	10xxxxxx	
 - 3 Bytes 1110xxxx	10xxxxxx	10xxxxxx	
 - 4 Bytes 11110xxx	10xxxxxx	10xxxxxx	10xxxxxx
## Project
In this project, we will write a method that determines if a given data set represents a valid UTF-8 encoding
