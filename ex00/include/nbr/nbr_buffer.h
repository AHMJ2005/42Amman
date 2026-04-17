#ifndef NBR_BUFFER_H
# define NBR_BUFFER_H

# include "nbr_type.h"

t_nbr_buffer	*nbr_buffer_new(void);
void			nbr_buffer_add(t_nbr_buffer *buffer, char *word);
void			nbr_buffer_print(t_nbr_buffer *buffer);
void			nbr_buffer_destroy(t_nbr_buffer *buffer);

#endif
