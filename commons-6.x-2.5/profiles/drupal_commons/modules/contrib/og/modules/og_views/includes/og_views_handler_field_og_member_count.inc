<?php
class og_views_handler_field_og_member_count extends views_handler_field_numeric {
  function init(&$view, $options) {
    parent::init($view, $options);
    $this->additional_fields['nid'] = array('table' => 'node', 'field' => 'nid');
  }

  function query() {
    $table = $this->query->ensure_table('og');
    $sql = og_list_users_sql(1, 0, NULL, TRUE);
    $sql = str_replace('%d', 'og.nid', $sql);
    $this->query->add_field('', "($sql)", 'member_count');
    $this->field_alias = 'member_count';
    $this->add_additional_fields();
  }
  
  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    $txt = $values->member_count;
    if (og_is_group_member($nid)) {
      $value = og_is_picture() ? l($txt, "og/users/$nid/faces") : l($txt, "og/users/$nid");
      return check_plain($this->options['prefix']) . $value . check_plain($this->options['suffix']);
    }
    else {
      return parent::render($values);
    }
  }
}

