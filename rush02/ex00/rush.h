/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:24:59 by acilione          #+#    #+#             */
/*   Updated: 2020/11/08 18:28:52 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_error(char *err);
void	ft_pr_w_dic(char *input, char *str, char suff_char);
void	ft_print_error(char *err);
void	ft_convert_three_dig_to_words(char *str, char *dict, int num_scale);
void	convert_num(char *num, char *dictionary);
void	complex_converter(char *num, char *dictionary, int num_scale);
void	ft_print_value(char *str, int i);
void	ft_print_int_num_in_words(int num, char *dic, int num_s);

char	last_c(int num_scale);
char	suff_last_char(char *num);
char	only_zeroes(char *num);

char	*ft_file_to_str(char *filename);
char	*ft_strstr(char *str, char *to_find);
char	*ft_itoa(int num);
char	*ft_strndup(char *src, unsigned int n);

int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_count_three_digits_groups(char *num_str);
int		ft_count_byte_file(char *filename);
int		ft_check_input(char *inp);
int		ft_check_format_error(char *dic);
#endif
