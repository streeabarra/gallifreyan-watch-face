#include <pebble.h>

//Evil global varables. Dont care, lazy.
static Window *my_window;
static GBitmap *backgroundBitmap;
static BitmapLayer *backgroundLayer;
static Layer *drawLayer;

static int hourTensPlace; 
static int hourOnesPlace;
static int minTensPlace;
static int minOnesPlace;



static const int NUM_POINTS = 10;
static GPathInfo PATH_INFO = {
  .num_points = 10,
	.points = (GPoint []) {{92, 31}, {97,34}, {100, 37}, {103, 42}, {104, 46}, {103, 50}, {100, 55}, {97,58}, {92,61},{88,30}}
};


//Updates PathInfo. Probably should hard code paths, use images, or something clever in the future to save batt & such
void CircleSegments(int radius, GPoint center, int startingDegree, int endingDegree)
{
    int numOfDegreees = endingDegree - startingDegree;
    int changeInI = numOfDegreees / NUM_POINTS;
	
	
	int currentDegree = startingDegree;
    for (int i = 0; i < NUM_POINTS; i++)
    {
		int angle = TRIG_MAX_ANGLE * currentDegree / 360;
		PATH_INFO.points[i].y = (-cos_lookup(angle) * radius / TRIG_MAX_RATIO) + center.y;
        PATH_INFO.points[i].x = (sin_lookup(angle) * radius / TRIG_MAX_RATIO) + center.x;

		
		currentDegree+=changeInI;
    }
}

//Draws digits
static void my_layer_draw(Layer *layer, GContext *ctx) { 

	GPoint hoursTenCenter = GPoint(44,84);
	GPoint hoursOneCenter = GPoint(88, 46);
	GPoint minsTenCenter = GPoint(73, 120);
	GPoint minsOneCenter = GPoint(120, 89);			
	GPath * outsidePathPtr;
	
	switch(hourTensPlace)
	{
	case 0:   
      graphics_context_set_stroke_color(ctx, GColorWhite);
      graphics_draw_line(ctx, GPoint(1,168),hoursTenCenter);
      graphics_draw_line(ctx, GPoint(1,167),GPoint(44,85));
      graphics_draw_line(ctx, GPoint(1,166),GPoint(44,86));
      graphics_draw_line(ctx, GPoint(1,165),GPoint(44,87));    
		break;
		case 1:
		    graphics_context_set_stroke_color(ctx, GColorWhite);
			graphics_draw_line(ctx, hoursTenCenter,GPoint(75,37));
      graphics_draw_line(ctx, GPoint(44,85),GPoint(75, 38));
			graphics_draw_line(ctx, GPoint(44,86),GPoint(75, 39));
			graphics_draw_line(ctx, GPoint(44,87),GPoint(75, 40));
		break;
		case 2:
	graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, hoursTenCenter , 16);
			graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, hoursTenCenter, 14);			
		default:
		break;
	};

	switch(hourOnesPlace)
	{
			case 0:    
      graphics_context_set_stroke_color(ctx, GColorWhite);
      graphics_draw_line(ctx, hoursOneCenter,GPoint(74,20));
      graphics_draw_line(ctx, GPoint(88,47),GPoint(74,21));
      graphics_draw_line(ctx, GPoint(88,48),GPoint(74,22));
      graphics_draw_line(ctx, GPoint(88,49),GPoint(74,23));
		break;
		case 1:
		    graphics_context_set_stroke_color(ctx, GColorWhite);
			graphics_draw_line(ctx, GPoint(38,61),hoursOneCenter);
		    graphics_draw_line(ctx, GPoint(38,62),GPoint(88,47));
			graphics_draw_line(ctx, GPoint(38,63),GPoint(88,48));
			graphics_draw_line(ctx, GPoint(38,64),GPoint(88,49));		
		break;
		
case 2:
			graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, hoursOneCenter , 16);
			graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, hoursOneCenter, 14);	
		break;
    
    		case 3:
    	graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, hoursOneCenter , 16);
    	graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, hoursOneCenter, 14);	
			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, hoursOneCenter , 10);		
    break;
    
       case 4:
    	graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, hoursOneCenter , 16);
    	graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, hoursOneCenter, 14);	
    			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, hoursOneCenter , 10);		
			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, hoursOneCenter , 6);

		break;
		
				case 7:
			CircleSegments(10, hoursOneCenter, 150, 320);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);	
      gpath_destroy(outsidePathPtr);
		case 6:
			CircleSegments(14, hoursOneCenter, 145, 328);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);
      gpath_destroy(outsidePathPtr);
		   	case 5:
			CircleSegments(18, hoursOneCenter, 147, 328);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);			
      gpath_destroy(outsidePathPtr);
    
		break;
		
		case 9:
			CircleSegments(11, hoursOneCenter, -50, 175);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);	
      gpath_destroy(outsidePathPtr);
		case 8:
			CircleSegments(17, hoursOneCenter, -50, 170);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);		
      gpath_destroy(outsidePathPtr);
	
		
		default:
		break;
	};
  
	switch(minTensPlace)  
	{
			case 0:
       graphics_context_set_fill_color(ctx, GColorWhite);
    graphics_draw_line(ctx, minsTenCenter,GPoint(87,167));
    graphics_draw_line(ctx, GPoint(73,121),GPoint(88,167));
    graphics_draw_line(ctx, GPoint(73,122),GPoint(89,167));
    graphics_draw_line(ctx, GPoint(73,123),GPoint(90,167));
		break;
    
		case 1:
		    graphics_context_set_stroke_color(ctx, GColorWhite);
			graphics_draw_line(ctx, minsTenCenter,GPoint(108,73));
	    graphics_draw_line(ctx, GPoint(73,121),GPoint(108,74));
			graphics_draw_line(ctx, GPoint(73,122),GPoint(108,75));
			graphics_draw_line(ctx, GPoint(73,123),GPoint(108,76));		
		break;
		
case 2:
			graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, minsTenCenter , 16);
			graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, minsTenCenter, 14);	
		break;
    
    		case 3:
    	graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, minsTenCenter , 16);
    	graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, minsTenCenter, 14);	
			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, minsTenCenter , 10);		
    break;
    
       case 4:
    	graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, minsTenCenter , 16);
    	graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, minsTenCenter, 14);	
    			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, minsTenCenter , 10);		
			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, minsTenCenter , 6);

		break;
    
			case 6:
			CircleSegments(10, minsTenCenter, -34, 143);//140,330
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);		
		  gpath_destroy(outsidePathPtr);
    case 5:
			CircleSegments(15, minsTenCenter, -35, 147);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);
      gpath_destroy(outsidePathPtr);
		
			break;
		
		
		default:
		break;
	};
	
	
	switch(minOnesPlace)
	{
				case 0:
    		 graphics_context_set_fill_color(ctx, GColorWhite);
    graphics_draw_line(ctx, minsOneCenter,GPoint(144,34));
    graphics_draw_line(ctx, GPoint(120,90),GPoint(144,33));
    graphics_draw_line(ctx, GPoint(120,91),GPoint(144,32));
    graphics_draw_line(ctx, GPoint(120,92),GPoint(144,31));
		break;
	
    case 1:
		    graphics_context_set_stroke_color(ctx, GColorWhite);
			graphics_draw_line(ctx, GPoint(65,105),minsOneCenter);
		    graphics_draw_line(ctx, GPoint(65,106),GPoint(120,90));
			graphics_draw_line(ctx, GPoint(65,107),GPoint(120,91));
			graphics_draw_line(ctx, GPoint(65,108),GPoint(120,92));		
		break;

       case 2:
			graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, minsOneCenter , 16);
			graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, minsOneCenter, 14);	
		break;
    
    		case 3:
    	graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, minsOneCenter , 16);
    	graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, minsOneCenter, 14);	
			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, minsOneCenter , 10);		
    break;
    
       case 4:
    	graphics_context_set_fill_color(ctx, GColorWhite);
   			graphics_fill_circle(ctx, minsOneCenter , 16);
    	graphics_context_set_fill_color(ctx, GColorBlack);
			graphics_fill_circle(ctx, minsOneCenter, 14);	
    			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, minsOneCenter , 10);		
			graphics_context_set_stroke_color(ctx, GColorWhite);
   			graphics_draw_circle(ctx, minsOneCenter , 6);

		break;
		
				case 7:
			CircleSegments(7, minsOneCenter, 163, 348);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);		
      gpath_destroy(outsidePathPtr);
				case 6:
			CircleSegments(11, minsOneCenter, 158, 352);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);
		  gpath_destroy(outsidePathPtr);
    case 5:
			CircleSegments(16, minsOneCenter, 162, 358);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);			
      gpath_destroy(outsidePathPtr);
		
			break;
		
				case 9:
			CircleSegments(11, minsOneCenter, -32, 180);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);		
      gpath_destroy(outsidePathPtr);
		case 8:
			CircleSegments(17, minsOneCenter, -31, 186);
			graphics_context_set_stroke_color(ctx, GColorWhite);		
			outsidePathPtr = gpath_create(&PATH_INFO);
			gpath_draw_outline(ctx,outsidePathPtr);	
    gpath_destroy(outsidePathPtr);


		
		default:
		break;
	};
	
}

//called once a min
static void handle_minute_tick(struct tm *tick_time, TimeUnits units_changed) {

	
	if(tick_time->tm_hour > 12 && !clock_is_24h_style())
	{
		tick_time->tm_hour -=12;
	}
	
	
	hourTensPlace = tick_time->tm_hour / 10; 
	minTensPlace = tick_time->tm_min / 10;
	minOnesPlace = tick_time->tm_min % 10;
	hourOnesPlace = tick_time->tm_hour % 10;
	
	layer_mark_dirty(drawLayer);
 }


void handle_init(void) {
	GRect bounds;
	Layer *window_layer;
	
	//Set up window
	my_window = window_create();
	window_stack_push(my_window, true /* Animated */);
	window_layer = window_get_root_layer(my_window);
	bounds = layer_get_frame(window_layer);
	
	//Create Bitmap from image
	backgroundBitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
	
	// Copied this from the pebble tutorial 
	backgroundLayer = bitmap_layer_create(bounds);
	bitmap_layer_set_bitmap(backgroundLayer, backgroundBitmap);
	bitmap_layer_set_alignment(backgroundLayer, GAlignCenter);
  	layer_add_child(window_layer, bitmap_layer_get_layer(backgroundLayer));
	
	//add the draw layer
	drawLayer = layer_create(bounds);
	layer_add_child(bitmap_layer_get_layer(backgroundLayer), (Layer*)drawLayer);
	
	//Callbacks
	tick_timer_service_subscribe(MINUTE_UNIT, handle_minute_tick);
	layer_set_update_proc((Layer*)drawLayer,my_layer_draw);
}

void handle_deinit(void) {
	tick_timer_service_unsubscribe();
	gbitmap_destroy(backgroundBitmap);
	bitmap_layer_destroy(backgroundLayer);
	layer_destroy(drawLayer);
	window_destroy(my_window);
}

int main(void) {
	handle_init();
	app_event_loop();
	handle_deinit();
}
