SET(README_manuallevel_FILES
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-assert-with-side-effects.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-container-inside-loop.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-detaching-member.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-heap-allocated-small-trivial-type.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-ifndef-define-typo.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-inefficient-qlist.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-isempty-vs-count.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-jni-signatures.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qhash-with-char-pointer-key.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qproperty-type-mismatch.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qrequiredresult-candidates.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qstring-varargs.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qt-keywords.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qt4-qstring-from-array.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qt6-deprecated-api-fixes.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qt6-header-fixes.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qt6-qhash-signature.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qt6-qlatin1stringchar-to-u.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qt6-fwd-fixes.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qvariant-template-instantiation.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-raw-environment-function.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-reserve-candidates.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-signal-with-return-value.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-thread-with-slots.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-tr-non-literal.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-unneeded-cast.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-use-chrono-in-qtimer.md
)

SET(README_LEVEL0_FILES
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-connect-by-name.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-connect-non-signal.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-connect-not-normalized.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-container-anti-pattern.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-empty-qstringliteral.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-fully-qualified-moc-types.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-lambda-in-connect.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-lambda-unique-connection.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-lowercase-qml-type-name.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-mutable-container-key.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-overloaded-signal.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qcolor-from-literal.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qdatetime-utc.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qenums.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qfileinfo-exists.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qgetenv.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qmap-with-pointer-key.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qstring-arg.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qstring-comparison-to-implicit-char.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qstring-insensitive-allocation.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qstring-ref.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qt-macros.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-strict-iterators.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-temporary-iterator.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-unused-non-trivial-variable.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-writing-to-temporary.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-wrong-qevent-cast.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-wrong-qglobalstatic.md
)

SET(README_LEVEL1_FILES
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-auto-unexpected-qstringbuilder.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-child-event-qobject-cast.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-connect-3arg-lambda.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-const-signal-or-slot.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-detaching-temporary.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-foreach.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-incorrect-emit.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-inefficient-qlist-soft.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-install-event-filter.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-non-pod-global-static.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-overridden-signal.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-post-event.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qdeleteall.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qhash-namespace.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qlatin1string-non-ascii.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qproperty-without-notify.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qstring-left.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-range-loop.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-returning-data-from-temporary.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-rule-of-two-soft.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-skipped-base-method.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-virtual-signal.md
)

SET(README_LEVEL2_FILES
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-base-class-event.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-copyable-polymorphic.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-ctor-missing-parent-argument.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-function-args-by-ref.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-function-args-by-value.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-global-const-char-pointer.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-implicit-casts.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-missing-qobject-macro.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-missing-typeinfo.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-old-style-connect.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-qstring-allocations.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-returning-void-expression.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-rule-of-three.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-static-pmf.md
    ${CMAKE_CURRENT_LIST_DIR}/docs/checks/README-virtual-call-ctor.md
)

