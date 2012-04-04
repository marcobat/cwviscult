<?php

/**
 * @file
 * Display utility functions for the 'Answers' module
 */

/**
 * Add settings relating to display to the admin form
 */
function _answers_display_settings() {
  $form = array();

  $form['answers_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display Settings'),
  );

  $form['answers_display']['answers_redirect_from_answer_to_question_nodes_p'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Redirect paths from answers to questions'),
    '#default_value' => variable_get('answers_redirect_from_answer_to_question_nodes_p', TRUE),
    '#description'   => t('This will redirect from showing answer nodes in page view to instead showing the question node in page view, scrolling down to the answer. (Recommended)'),
  );

  return $form;
}

function _answers_display_nodeapi(&$node, $op, $teaser, $page) {
  if (($op == 'view') && variable_get('answers_redirect_from_answer_to_question_nodes_p', TRUE)) {
    if (($node->type == 'answer') && $page) {
      $question_nid = $node->field_answer_question[0]['nid'];
      if ($question_nid) {
        drupal_goto('node/' . $question_nid, NULL, 'node-' . $node->nid);
      }
    }
  }
}
 