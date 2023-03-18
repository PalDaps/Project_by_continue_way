#include <iostream>

//
// Write a search function for the first 
// occurrence of the template in the text. 
// As the first parameter, the function 
// takes the text (C-style string) in 
// which to search for a template.
//
int strstr_mine(const char* text, const char* pattern)
{
	int counter = 0, length = 0;
	const char* ptr_safe_text = 0;
	const char* ptr_safe_pattern = 0;
	const char* ptr_first_text = &text[0];
	const char* ptr_first_pattern = &pattern[0];
	if ( *ptr_first_pattern == '\0') return 0;
	/* while (*ptr_first_pattern != '\0')
	{
		ptr_first_pattern++;
		length++;
		}
	*/ 
	ptr_first_pattern = &pattern[0];
	for (ptr_first_text; *ptr_first_text != '\0'; ptr_first_text++)
	{
		if (*ptr_first_text == *ptr_first_pattern)
		{
			ptr_safe_text = ptr_first_text;
			ptr_safe_pattern = ptr_first_pattern;
			counter++;
			ptr_first_text++;
			ptr_first_pattern++;
			for (ptr_first_text, ptr_first_pattern; *ptr_first_pattern != '\0'; ptr_first_text++, ptr_first_pattern++)
			{
				if (*ptr_first_text == *ptr_first_pattern)
				{
					counter++;
				}
			}
			ptr_first_text = ptr_safe_text;
			ptr_first_pattern = ptr_safe_pattern;
			break;
		}
	}
	ptr_first_text = &text[0];
	if (ptr_safe_text == nullptr) return -1;
	while (*ptr_first_text != *ptr_safe_text)
	{
		ptr_first_text++;
		length++;
	}
	return length;
}

int main()
{
	char text[] = "avavc";
	char pattern[] = "avc";
	std::cout << strstr_mine(text, pattern);

	return 0;
}