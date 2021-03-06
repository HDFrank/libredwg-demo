#include "common.c"
#include <dejagnu.h>
/// Output processing function
void output_process (dwg_object * obj);

/// Checks the respective DWG entity/object type and then calls the output_process()
void
output_object (dwg_object * obj)
{
  if (!obj)
    {
      printf ("object is NULL\n");
      return;
    }

  if (dwg_get_type (obj) == DWG_TYPE_MTEXT)
    {
      output_process (obj);
    }
}

void
low_level_process (dwg_object * obj)
{
  // casting object to mtext entity
  dwg_ent_mtext *mtext = dwg_object_to_MTEXT (obj);

  // prints extends ht
  printf ("extends ht of mtext : %f\t\n", mtext->extends_ht);

  // prints extends wid
  printf ("extends wid of mtext : %f\t\n", mtext->extends_wid);

  // prints drawing dir
  printf ("drawing dir of mtext : %ud\t\n", mtext->drawing_dir);

  // prints linespace style
  printf ("linespace style of mtext : %ud\t\n", mtext->linespace_style);

  // prints attachment
  printf ("attachment of mtext : %ud\t\n", mtext->attachment);

  // prints text value
  printf ("text of mtext : %s\t\n", mtext->text);

  // prints mtext rect_height
  printf ("rect height of mtext : %f\t\n", mtext->rect_height);

  // prints mtext rect_width
  printf ("rect width of mtext : %f\t\n", mtext->rect_width);

  // prints mtext linespace factor
  printf ("linespace factor of mtext : %f\t\n", mtext->linespace_factor);

  // prints mtext extrusion
  printf ("extrusion of mtext : x = %f, y = %f, z = %f\t\n",
	  mtext->extrusion.x, mtext->extrusion.y, mtext->extrusion.z);

  // prints mtext extrusion
  printf ("insertion point of mtext : x = %f, y = %f, z = %f\t\n",
	  mtext->insertion_pt.x, mtext->insertion_pt.y,
	  mtext->insertion_pt.z);

  // prints mtext x_axis_dir
  printf ("x_axis_dir of mtext : x = %f,y = %f,z = %f\t\n",
	  mtext->x_axis_dir.x, mtext->x_axis_dir.y, mtext->x_axis_dir.z);
}

void
api_process (dwg_object * obj)
{
  int attachment_error, rect_height_error, rect_width_error, text_height_error, extends_ht_error, extends_wid_error, linespace_factor_error, drawing_dir_error, ext_error, x_axis_dir_error, ins_pt_error, linespace_style_error, text_error;	// Error reporting
  float rect_height, rect_width, text_height, extends_ht, extends_wid,
    linespace_factor;
  unsigned int attachment, drawing_dir, linespace_style;
  char *text;
  dwg_point_3d ins_pt, ext, x_axis_dir;	//3d_points 

  // casting object to mtext entity
  dwg_ent_mtext *mtext = dwg_object_to_MTEXT (obj);

  // returns mtext drawing dir
  extends_ht = dwg_ent_mtext_get_extends_ht (mtext, &extends_ht_error);
  if (extends_ht_error == 0 && extends_ht == mtext->extends_ht)	// Error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading extends ht");
    }

  // returns mtext drawing dir
  extends_wid = dwg_ent_mtext_get_extends_wid (mtext, &extends_wid_error);
  if (extends_wid_error == 0 && extends_wid == mtext->extends_wid)	// Error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading extends wid");
    }

  // returns mtext drawing dir
  drawing_dir = dwg_ent_mtext_get_drawing_dir (mtext, &drawing_dir_error);
  if (drawing_dir_error == 0 && drawing_dir == mtext->drawing_dir)	// Error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading drawing dir");
    }

  // returns mtext linespace_style
  linespace_style = dwg_ent_mtext_get_linespace_style (mtext,
						       &linespace_style_error);
  if (linespace_style_error == 0 && linespace_style == mtext->linespace_style)	// Error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading linespace style");
    }

  // returns mtext attachment
  attachment = dwg_ent_mtext_get_attachment (mtext, &attachment_error);
  if (attachment_error == 0 && attachment == mtext->attachment)	// Error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading attachment");
    }

  // returns mtext rect_height
  text = dwg_ent_mtext_get_text (mtext, &text_error);
  if (text_error == 0 && !strcmp (text, mtext->text))	// Error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading text");
    }

  // returns mtext rect_height
  rect_height = dwg_ent_mtext_get_rect_height (mtext, &rect_height_error);
  if (rect_height_error == 0 && rect_height == mtext->rect_height)	// Error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading rect_height");
    }

  // returns mtext rect_width
  rect_width = dwg_ent_mtext_get_rect_width (mtext, &rect_width_error);
  if (rect_width_error == 0 && rect_width == mtext->rect_width)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading rect_width");
    }

  // returns mtext linespace factor 
  linespace_factor = dwg_ent_mtext_get_linespace_factor (mtext,
							 &linespace_factor_error);
  if (linespace_factor_error == 0 && linespace_factor == mtext->linespace_factor)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading linespace factor");
    }

  // returns mtext extrusion
  dwg_ent_mtext_get_extrusion (mtext, &ext, &ext_error);
  if (ext_error == 0 && ext.x == mtext->extrusion.x && ext.y == mtext->extrusion.y && ext.z == mtext->extrusion.z)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading extrusion");
    }

  dwg_ent_mtext_get_insertion_pt (mtext, &ins_pt, &ins_pt_error);
  if (ins_pt_error == 0 && ins_pt.x == mtext->insertion_pt.x && ins_pt.y == mtext->insertion_pt.y && ins_pt.z == mtext->insertion_pt.z)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading insertion point");
    }

  // return mtext x_axis_dir points
  dwg_ent_mtext_get_x_axis_dir (mtext, &x_axis_dir, &x_axis_dir_error);
  if (x_axis_dir_error == 0 && x_axis_dir.x == mtext->x_axis_dir.x && x_axis_dir.y == mtext->x_axis_dir.y && x_axis_dir.z == mtext->x_axis_dir.z)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading x_axis_dir");
    }

}
