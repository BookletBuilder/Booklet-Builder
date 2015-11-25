<?php mustache_js_load() ?>
<script 
  type="application/x-template"
  <?php if (isset($template_id)): ?>
    id = "<?php echo $template_id ?>"
  <?php endif ?>
  <?php if (isset($template_classes)): ?>
    classes="<?php echo implode(' ', $template_classes) ?>"
  <?php endif ?>
>
<?php echo $template ?>
</script>
