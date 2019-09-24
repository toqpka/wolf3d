/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_prototypes.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:51:21 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/17 23:57:39 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_PROTOTYPES_H
# define WOLF3D_PROTOTYPES_H

/*
** Main functions
*/
int						global_init(t_window *w);
void					init_riffle(t_window *w);
void					fill_ui(t_window *w);
void					re_init_riffle(t_window *w, int key);
void					load_assets(t_window *w);
int						load_sounds(t_window *w);

void					count_delta_time(t_window *w);
void					sounds_animation(t_window *w);

int						clear_image(t_window *window);
void					draw_cycle(t_window *w);
int						read_map(t_window *wolf, char *path);
void					render_walls(t_window *w);
void					raycasting(t_window *w, int x);
void					move_controls(t_window *w);
void					draw_background(t_window *w);

int						volume_control(t_window *w);
t_image					*scale_bilin(SDL_Rect *rect, t_image *image);
t_image					*scale_img(t_image *img, SDL_Rect r);
void					render_image(t_window *w, t_ui_node *img_c);
void					render_scale(t_window *w, t_ui_node *img_c);
void					render_scale_r(t_window *w,
						t_ui_node *img_c, SDL_Rect rect);
t_ui_node				*scale(t_ui_node *img_c, int percent);

void					cast_floor(t_window *w);
void					set_pixel(SDL_Surface *surf, const int x, const int y,
							const int color);
void					ui_bar(t_window *w);
void					show_menu(t_window *w);

void					make_shot(t_window *w);
void					weapon_animation(t_window *w);
void					weapon_shoot(t_window *w, int key);
void					weapon_fraps(t_window *w, int key);

void					move_forward(t_window *w, double dist);
void					move_backward(t_window *w, double dist);
void					move_left(t_window *w, double dist);
void					move_right(t_window *w, double dist);
void					rotate_move(t_window *w, double rotate);

t_u8					open_error(char *path);
t_u8					mem_error(TGA *tga);
t_u8					unsupported_error(TGA *tga);
t_u8					get_tga_info(char *path);
t_image					*read_tga(char *path);
void					load_paths_raw(t_window *w, char *path);

void					ft_setinrange(int *num, int min, int max);
void					print_arr(t_map *map);
void					face_animation(t_window *w);
Uint32					set_color(t_rgba rgb);
Uint32					form_color(int red, int green, int blue, int alpha);
t_rgba					inter_color(Uint32 *pixels,
						float x_diff, float y_diff, int w);
SDL_Rect				set_rect(int w, int h, int x, int y);
int						shade_color(int color, double percent);
void					draw_mask_backround(t_window *w);
void					draw_skill(t_window *w, int index);
void					draw_menu_background(t_window *w);
void					face_animation(t_window *w);
void					get_menu_offset_by_index(int index,
						int *offset_x, int *offset_y);
void					fill_ui(t_window *w);
void					re_init_riffle(t_window *w, int key);

int						get_world_side(t_window *w);
void					calc_c_height(t_window *w, int tex_num);

t_u8					key_action(SDL_Event *ev, int32_t
						key_code, Uint32 press);
t_u8					switch_key(t_window *w, char key, t_u8 *key_tr);
t_u8					handle_key(t_window *w, char key, t_u8 *key_tr);

void					scale_rect_digits(t_window *w, float scale_k);
int						get_text_height(char *path);
void					load_paths_raw(t_window *w, char *path);
t_image					*not_found_img();
#endif
