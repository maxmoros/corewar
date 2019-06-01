/**
 * File              : lexer.c
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 25.05.2019
 * Last Modified Date: 25.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include <assembler.h>

size_t		g_offset = 0;

/*
** Replaces in str every occurence of a by b.
*/
static void	replace(char *str, char a, char b)
{
	while (*str)
	{
		if (*str == a)
			*str = b;
		str++;
	}
}

/*
** Parses a line into an instruction and possibly a label.
*/
t_error		parse_line(t_vector *instructions, t_vector *labels, char *line)
{
	char		**elem;
	t_label		*new_label;
	t_instruction	*new_instruction;
	t_error		err;

	printf(RED"parse_line:\n"RESET);
	new_label = NULL;
	new_instruction = NULL;
	replace(line, TAB, WHITE_SPACE);
	replace(line, WHITE_SPACE, SEPARATOR_CHAR);
	elem = ft_strsplit(line, SEPARATOR_CHAR);
	if (!elem || !elem[0])
		return ft_strdup("could not split the line");
	err = get_label(&new_label, elem);
	if (err)
		return err;
	if (new_label)
		VECTOR_ADD(labels, new_label);
	err = get_instruction(&new_instruction, elem);
	printf(RED"parse_line1:\n"RESET);
	if (err)
		return err;
	if (new_instruction)
		VECTOR_ADD(instructions, new_instruction);
	printf(RED"parse_line2:\n"RESET);
	return NULL;
}

/*
** Feeds the label references in instructions' arguments with the according
** label offset. Return an error if the label does not exist.
*/
t_error		feed_references(t_vector *instructions, t_vector *labels)
{
	printf(RED"feed_references:\n"RESET);
	(void)instructions;
	(void)labels;
	return NULL;
}

/*
** Transforms the t_champ struct into a list of instructions, verifies
** that instructions are valid and returns err if they are not.
*/
t_error		lexer(t_vector *instructions, t_champ *champ)
{
	char		**lines;
	int		i;
	t_vector	labels;
	t_error		err;

	printf(RED"lexer:\n"RESET);
	VECTOR_INIT(&labels);
	lines = ft_strsplit(champ->content, NEWLINE);
	if (!lines)
		return ft_strdup(RED"could not split into array of lines"RESET);
	i = 0;
	while (lines[i])
	{
		err = parse_line(instructions, &labels, lines[i]);
		if (err)
			return err;
		i++;

	}
	err = feed_references(instructions, &labels);
	if (err)
		return err;
	return NULL;
}






















	// split champ->content into array of lines
	// for each line, split by space:
	//
	// 			if label:
	// 				append label to label_array,
	// 					with offset = total_instruction_size before label
	// 			if instructions:
	// 				create instruction struct
	// 				determine instruction size
	// 				add instruction size to total_instruction_size
	// 				append instruction to instruction_array
	// 					check format
	// 			if #:
	// 				ignore rest
	// 			else if anything else
	// 				format error
	//
