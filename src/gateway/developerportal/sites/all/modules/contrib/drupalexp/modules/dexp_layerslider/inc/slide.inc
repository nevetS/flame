<?php

function dexp_layerslider_load($sid) {
  $result = db_select('{dexp_layerslider}', 'd')
          ->fields('d')
          ->condition('id', $sid, '=')
          ->execute()
          ->fetchObject();
  $slideshow = new stdClass();
  $json = base64_decode($result->settings);
  $slideshow->settings = json_decode($json);
  $json = base64_decode($result->data);
  $slideshow->slides = json_decode($json);
  
  /** showing register layer only based on logged out user **/
  global $user;
  //user logged in
  if ( $user->uid ) {
		for ($i = 0; $i < count($slideshow->slides); $i++) {
		if (!empty($slideshow->slides[$i]->background_image_uri)) {
		  $slideshow->slides[$i]->background_image = file_create_url($slideshow->slides[$i]->background_image_uri);
		}
		for ($j = 0; $j < count($slideshow->slides[$i]->layers); $j++) {
			if ($slideshow->slides[$i]->layers[$j]->type == 'image' && !empty($slideshow->slides[$i]->layers[$j]->image_uri)) {
			$slideshow->slides[$i]->layers[$j]->image = file_create_url($slideshow->slides[$i]->layers[$j]->image_uri);
		  }
		  //set up different layers ahead
			if($slideshow->slides[$i]->layers[$j]->title == 'register_layer')
			{
				$slideshow->slides[$i]->layers[$j]->text=''; 
			}
		}
	  }
  }
  else
  {
	for ($i = 0; $i < count($slideshow->slides); $i++) {
		if (!empty($slideshow->slides[$i]->background_image_uri)) {
		  $slideshow->slides[$i]->background_image = file_create_url($slideshow->slides[$i]->background_image_uri);
		}
		for ($j = 0; $j < count($slideshow->slides[$i]->layers); $j++) {
		  if ($slideshow->slides[$i]->layers[$j]->type == 'image' && !empty($slideshow->slides[$i]->layers[$j]->image_uri)) {
			$slideshow->slides[$i]->layers[$j]->image = file_create_url($slideshow->slides[$i]->layers[$j]->image_uri);
		  }
		  if($slideshow->slides[$i]->layers[$j]->title == 'register_layer')
			{
				$slideshow->slides[$i]->layers[$j]->text='<a href="user/register" style="color:#fff; padding:15px 100px;display:block; background:#ee5425; font-size:35px; border-radius: 10px">REGISTER</a>';
			}
		}
	  }
  }
  if(!is_object($slideshow->settings)){
    $slideshow->settings = new stdClass();
  }
  if(!isset($slideshow->settings->hideThumbs)){
    $slideshow->settings->hideThumbs = 0;
  }
  if(!isset($slideshow->settings->thumbWidth)){
    $slideshow->settings->thumbWidth = 150;
  }
  if(!isset($slideshow->settings->thumbHeight)){
    $slideshow->settings->thumbHeight = 100;
  }
  if(!isset($slideshow->settings->thumbAmount)){
    $slideshow->settings->thumbAmount = 3;
  }
  if(!isset($slideshow->settings->dottedOverlay)){
    $slideshow->settings->dottedOverlay = 'none';
  }
  return $slideshow;
}