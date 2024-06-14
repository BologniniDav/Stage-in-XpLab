
int forward=A1; 
int reverse=A2;
void loop(){ 
//rotate clockwise 

analogWrite(forward,1024); 
analogWrite(reverse,0); 
// now reverse the rotation; 
analogWrite(forward,0); 
analogWrite(reverse,1024); 
}
